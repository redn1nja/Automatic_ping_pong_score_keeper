/*CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "crc.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "usart.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdarg.h"
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"
#include "usbd_cdc_if.h"
using namespace ei;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
float features[] =
		{1279.2060, 1536.0835, 1536.4737, 1534.8988, 1538.5694,
				1534.9339, 1535.1841, 1538.4926, 1530.2236, 1282.9574, 1534.5426, 1279.1321, 1541.1327, 1534.7125, 1534.5404, 1542.0519, 1792.7286, 1526.8600, 1543.5307, 1802.2556, 2051.1182, 1772.7264, 1542.0222, 1794.7253, 1519.9242, 1553.3715, 1784.4459, };
//				1251.8288, 1310.7237, 1798.5710, 1797.4764, 1770.7899, 1261.9833, 1284.2813, 1285.8882, 1545.2028, 1249.0045, 1314.5444, 1514.3916, 1298.2039, 1816.5235, 1485.7560, 1591.7667, 1469.5772, 1611.0728, 1749.4354, 1843.1364, 1716.5899, 2034.3441, 3194.9452, -18421.1549, 5435.8034, 12902.5358, -28890.0420, 31510.5646, 685.1447, -24592.9184, -8079.1743, -8532.6863, -2215.1476, -3005.6811, -4859.3972, -5118.8958, -681.9285, 3917.0156, 4151.8727, 9095.1016, 3488.9416, -4462.5021, 4757.4698, 12838.4739, 13113.8332, 7192.3407, -9651.6729, -11355.3410, -2742.0928, 5298.0306, 8280.3185, 6884.0653, 377.4861, -5088.0643, -13083.0518, -11757.6964, -8397.8751, 3639.4366, 11226.2833, 12826.7770, 8207.2456, 6359.7408, 4986.4968, 2393.9876, -1842.7366, -2366.1676, 4683.1040, 9304.2909, 7953.0607, 881.7485, -3996.5260, -10697.1703, -11282.1769, -8888.0920, 1005.5057, 7912.9753, 9540.9773, 3039.3982, -1646.1256, -2105.1670, 3874.7426, 8097.7130, 8317.8457, 6406.5270, 3505.6420, 11.0893, -2624.2422, -3930.8954, -5203.7185, -4772.1039, -3674.6126, -1113.3233, 37.7334, 3020.6556, 3847.9817, 2028.7180, 1704.9333, 70.1517, 221.2607, 4821.4180, 9544.0444, 10630.8714, 8173.4346, 3329.5582, -1341.5961, -3030.9453, -3349.2461, -3227.3483, -448.4391, 4102.6601, 3512.8567, 526.9972, -2492.5021, -2948.0222, 1710.0090, 6082.7790, 6070.9452, 3562.8569, -288.4478, -3300.5397, -2581.2935, -493.2247, 3113.5865, 8802.3037, 10661.7017, 6130.2127, -1513.9163, -7485.0021, -7489.4448, 1.2621, 6202.4398, 8291.9321, 4934.0973, -606.4532, -2290.9345, -214.3485, 2907.4788, 4014.3334, 1170.2059, -2332.5286, -2407.2917, 989.5994, 5275.7837, 6924.4863, 3710.2407, -919.0971, -1908.7107, -125.7186, 1915.2545, 3837.4877};
//static float features[] =
//		{1885.3781, 2621.3143, 2386.2738, 2518.3997, 2431.9176,
//				2507.8625, 2450.8165, 2479.7419, 2471.9349, 2485.3773,
//				2485.0385, 2464.4878, 2462.8709, 2471.7998, 2449.6698,
//				2494.5335, 2502.9620, 2482.9162, 2443.3203, 2486.2656,
//				2501.7580, 2524.7427, 2582.2399, 2514.9058, 2504.5065,
//				2468.6755, 2531.2172, 2492.1379, 2498.8317, 2516.9022, 2509.2742, 2470.6026, 2505.1213, 2518.6949, 2517.4841, 2525.5654, 2525.3428, 2539.1571, 2519.6324, 2526.2584, 2532.2948, 2537.8981, 2538.9300, 2537.2832, 2537.9397, 2541.1048, 2549.9967, 2549.6641, 2543.8244, 2544.0925, 2553.2190, 2558.6315, 2574.2700, 2573.1071, 2576.4620, 2579.9821, 2583.3200, 2582.4430, 2583.0847, 2595.7684, 2593.8583, 2583.0942, 2596.8924, 2596.4298, 2595.4570, 2599.4650, 2607.0363, 2602.9226, 2597.1584, 2609.6130, 2610.7610, 2618.4764, 2616.3800, 2634.0363, 2624.7649, 2643.6454, 2602.9466, 2590.6834, 2645.9193, 2622.9725, 2644.2343, 2635.1112, 2643.3290, 2656.2478, 2629.9788, 2632.5185, 2657.0350, 2660.3200, 2665.7466, 2667.6980, 2659.2607, 2665.4041, 2675.1639, 2652.2617, 2662.8999, 2670.9071, 2674.2785, 2673.8920, 2681.8246, 2697.0081, 2659.9382, 2707.3006, 2688.7870, 2691.9612, 2686.7279, 2693.0771, 2723.1887, 2701.6300, 2801.5390, 2727.5602, 2743.9021, 2757.8082, 2676.2277, 2786.1303, 2747.5064, 2757.8284, 2765.4000, 2739.7069, 2718.7437, 2741.3288, 2756.3010, 2757.2683, 2749.5426, 2763.7727, 2763.3389, 2747.7314, 2762.4180, 2756.1463, 2759.9780, 2768.0674, 2768.3670, 2773.6812, 2787.2323, 2778.0325, 2775.2731, 2788.0689, 2808.8509, 2777.4630, 2779.4358, 2792.5648, 2791.1004, 2783.9042, 2812.7666, 2804.2394, 2806.4852, 2805.2805, 2807.8846, 2805.5331, 2800.4602, 2813.7637, 2834.1569, 2821.9152, 2816.5539, 2825.0999, 2828.6648, 2935.0022, 2911.8751, 2833.3216, 2989.1403, 2956.4398, 2768.0904, 2711.7631, 2900.1775, 2999.8835, 2748.6684, 2885.5814, 2822.3724, 2630.9776, 2832.8247, 2870.2828, 2874.2900, 2832.8064, 3048.8825, 2844.4920, 2699.4921, 2850.9678, 2958.7655, 2882.2669, 2601.5430, 2833.0584, 2736.4528, 2884.5141, 2926.8442, 2693.7215
//		};
void vprint(const char *fmt, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string, fmt, argp)) // build string
    {
    	HAL_UART_Transmit(&huart2, (uint8_t*)string, strlen(string), 0xffffff);
    }
}

void ei_printf(const char *format, ...) {
    va_list myargs;
    va_start(myargs, format);
    vprint(format, myargs);
    va_end(myargs);
}
int get_feature_data(size_t offset, size_t length, float *out_ptr) {
//	memcpy(out_ptr, features, sizeof(features));
	for (size_t var = 0; var < sizeof(features)/sizeof(features[0]); ++var) {
		out_ptr[var] = (features)[var];
		ei_printf_float(out_ptr[var]);
		ei_printf(" ");
	}
	ei_printf("\n\n\n\n\n");
	ei_printf("%l", offset);
	 return 0;
}
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//ADC_HandleTypeDef hadc1;
//TIM_HandleTypeDef htim2;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint16_t maxym = 0;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	signal_t signal;
	signal.total_length = EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE;
	signal.get_data = &get_feature_data;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_USB_DEVICE_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_CRC_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
//  char* str = malloc(100);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  	for (int var = 0; var < sizeof(features)/sizeof(features[0]); ++var) {
		ei_printf_float(features[var]);
		ei_printf(" ");
	}
  	ei_printf("\n\n\n");
	ei_impulse_result_t result = { 0 };
	EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);
	ei_printf("run_classifier returned: %d\n", res);

	ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
	  result.timing.dsp, result.timing.classification, result.timing.anomaly);

	// print the predictions
	ei_printf("[");
	for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
	  ei_printf_float(result.classification[ix].value);
	#if EI_CLASSIFIER_HAS_ANOMALY == 1
	  ei_printf(", ");
	#else
	  if (ix != EI_CLASSIFIER_LABEL_COUNT - 1) {
		  ei_printf(", ");
	  }
	#endif
	}
	#if EI_CLASSIFIER_HAS_ANOMALY == 1
	ei_printf_float(result.anomaly);
	#endif
	ei_printf("]\n\n\n");
//	HAL_ADC_Start(&hadc1);
//	for(uint8_t i = 0; i<200; ++i){
//	HAL_ADC_PollForConversion(&hadc1, 1);
//		// Read The ADC Conversion Result & Map It To PWM DutyCycle
//		maxym = HAL_ADC_GetValue(&hadc1);
//
//	}





//		CDC_Transmit_FS(reinterpret_cast<uint8_t*>(&maxym), 2*200);
  }
//  free(str);
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB|RCC_PERIPHCLK_I2C1
                              |RCC_PERIPHCLK_ADC12;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.USBClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
