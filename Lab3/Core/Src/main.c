/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"  // Exercise 4: Include software timer
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
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

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  
  /* ========================================================================
   * EXERCISE 4: KHỞI TẠO HỆ THỐNG
   * ========================================================================
   */
  
  // 1. Khởi tạo software timer system
  timer_init();
  
  // 2. Bật timer interrupt TIM2 (10ms)
  HAL_TIM_Base_Start_IT(&htim2);
  
  // 3. Setup các timer cần thiết cho demo
  setTimer(TIMER_LED_BLINK, 250);      // LED nhấp nháy 2Hz (250ms toggle)
  setTimer(TIMER_TRAFFIC_LIGHT, 5000); // Đèn giao thông 5s
  
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    
    /* ========================================================================
     * EXERCISE 4: DEMO - TEST SOFTWARE TIMER
     * ========================================================================
     * Ví dụ: Nhấp nháy LED mỗi 250ms (tần số 2Hz)
     */
    
    if (isTimerExpired(TIMER_LED_BLINK)) {
        clearTimer(TIMER_LED_BLINK);
        
        // TODO: Toggle LED ở đây
        // HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        
        // Set lại timer
        setTimer(TIMER_LED_BLINK, 250);
    }
    
    // Ví dụ timer cho đèn giao thông
    if (isTimerExpired(TIMER_TRAFFIC_LIGHT)) {
        clearTimer(TIMER_TRAFFIC_LIGHT);
        
        // TODO: Chuyển trạng thái đèn giao thông
        
        // Set lại timer
        setTimer(TIMER_TRAFFIC_LIGHT, 5000);
    }

	}

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_2_Pin|LED_YELLOW_2_Pin
                          |LED_RED_2_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED7SEG_0_Pin|LED7SEG_1_Pin|LED7SEG_2_Pin|LED7SEG_3_Pin
                          |LED7SEG_4_Pin|LED7SEG_5_Pin|LED7SEG_6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_GREEN_1_Pin LED_YELLOW_1_Pin LED_GREEN_2_Pin LED_YELLOW_2_Pin
                           LED_RED_2_Pin EN0_Pin EN1_Pin EN2_Pin
                           EN3_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_2_Pin|LED_YELLOW_2_Pin
                          |LED_RED_2_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_RED_1_Pin */
  GPIO_InitStruct.Pin = LED_RED_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LED_RED_1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED7SEG_0_Pin LED7SEG_1_Pin LED7SEG_2_Pin LED7SEG_3_Pin
                           LED7SEG_4_Pin LED7SEG_5_Pin LED7SEG_6_Pin */
  GPIO_InitStruct.Pin = LED7SEG_0_Pin|LED7SEG_1_Pin|LED7SEG_2_Pin|LED7SEG_3_Pin
                          |LED7SEG_4_Pin|LED7SEG_5_Pin|LED7SEG_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_2_Pin BUTTON_0_Pin BUTTON_1_Pin */
  GPIO_InitStruct.Pin = BUTTON_2_Pin|BUTTON_0_Pin|BUTTON_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* ============================================================================
 * EXERCISE 4: TIMER INTERRUPT CALLBACK
 * ============================================================================
 * Hàm này được gọi TỰ ĐỘNG bởi HAL mỗi khi timer interrupt xảy ra
 * 
 * Với cấu hình TIM2:
 * - Prescaler: 7199
 * - Period: 99
 * - Clock: 72MHz
 * → Interrupt mỗi 10ms
 * 
 * Công thức: T = (Prescaler + 1) * (Period + 1) / Clock
 *           T = (7199 + 1) * (99 + 1) / 72,000,000
 *           T = 7200 * 100 / 72,000,000
 *           T = 0.01s = 10ms
 * ============================================================================
 */

/**
 * @brief  Timer Interrupt Callback
 * @param  htim: Timer handle
 * @note   Hàm này OVERRIDE hàm __weak trong HAL library
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    // Kiểm tra đúng timer TIM2
    if (htim->Instance == TIM2) {
        // Gọi hàm xử lý tất cả software timers
        timer_run();
        
        // TODO: Thêm các xử lý khác nếu cần
        // VD: button_reading(); (Exercise 5)
    }
}

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
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
