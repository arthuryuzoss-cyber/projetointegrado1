/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "st7735/st7735.h"
#include <stdlib.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define lerbotao9   HAL_GPIO_ReadPin(BOTAOPA9_GPIO_Port, BOTAOPA9_Pin)
#define lerbotao10   HAL_GPIO_ReadPin(BOTAOPA10_GPIO_Port, BOTAOPA10_Pin)
#define lerbotao11   HAL_GPIO_ReadPin(BOTAOPA11_GPIO_Port, BOTAOPA11_Pin)
#define lerbotao12   HAL_GPIO_ReadPin(BOTAOPA12_GPIO_Port, BOTAOPA12_Pin)


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE BEGIN 0 */
void atualizarBarra(int atual, int max) {
    int larguraBarraFundo = 100;
    int alturaBarra = 12;
    int xBarra = 14;
    int yBarra = 60;

    if (max > 0) {
        int preenchimento = (atual * larguraBarraFundo) / max;

        // 1. Borda
        ST7735_FillRectangle(xBarra - 1, yBarra - 1, larguraBarraFundo + 2, alturaBarra + 2, WHITE);

        // 2. Parte preenchida
        ST7735_FillRectangle(xBarra, yBarra, preenchimento, alturaBarra, GREEN);

        // 3. Parte vazia (limpa o rastro se o aluno sair)
        ST7735_FillRectangle(xBarra + preenchimento, yBarra, larguraBarraFundo - preenchimento, alturaBarra, BLACK);
    }
}
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
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  ST7735_Init();
  int caracter1=0;
  int caracter2=0;
  int caracter3=0;
  int caracter4=0;
  int alunosD=0;
  int alunosU=0;
  int alunos=0;
int alunosfora=0;
int senhadigitada=0;
int tentativas = 0;
int bloqueado = 0;
int senhacorreta=0;
uint32_t tempoBloqueio = 0;
int botao9=0;
int botao10=0;
int botao11=0;
int botao12=0;
int saidas=0;
int matricula=0;
int alunosvieram=0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1){
	  botao9=lerbotao9;
	  if (botao9 == 0){
		  botao9=lerbotao9;
		  ST7735_FillScreen(WHITE);
		  HAL_Delay(1000);
		  ST7735_WriteString(1,15, "Bem vindo a aula      digite a senha", Font_7x10,BLACK, WHITE);
		  HAL_Delay(1000);
	  int senha = (rand() % 9999);
	                while (senhacorreta == 0){
	               			  if (bloqueado == 1){
	               				  if (HAL_GetTick() - tempoBloqueio >= 10000){
	               					  bloqueado = 0;
	               					  tentativas = 0;
	               									  }
	               				  else{
	               					  ST7735_FillScreen(WHITE);
	               					  ST7735_WriteString(10,30,"BLOQUEADO POR 10S",Font_11x18,GREEN,WHITE);
	               					  HAL_Delay(100);
	               					  continue;
	               				  }
	               			  }
	                while (senhacorreta == 0 && bloqueado == 0) {
	                	botao11=lerbotao11;
	  while (botao11==1){//primeiro caracter
		  botao11=lerbotao11;
		  botao12=lerbotao12;
	 if (botao12==0 && caracter1<9){
		 botao12=lerbotao12;
		 caracter1++;

	 }
	 botao10=lerbotao10;
	  if (botao10==0){
		  botao10=lerbotao10;
		 caracter1--;
	 }
	  ST7735_FillScreen(WHITE);
		  	  //char c = itoa(caracter1);
		  	char c1[2];
		  	c1[0] = caracter1 + '0';
		  	c1[1] = '\0';
		  	ST7735_WriteString(5, 15, c1, Font_16x26, BLACK, WHITE);
		  	HAL_Delay (1000);
	  }
	  botao11=lerbotao11;
	  while (botao11==0){
		  botao11=lerbotao11;
		  HAL_Delay(100);
	  }
	  botao11=lerbotao11;
	  while (botao11==1){//segundo caracter
		  botao11=lerbotao11;
		  botao12=lerbotao12;
	 if (botao12==0 && caracter2<9){
		 botao12=lerbotao12;
		 caracter2++;
	 }
	 botao10=lerbotao10;
	  if (botao10==0){
		  botao10=lerbotao10;
		 caracter2--;
	 }

	 		  	  //char c = itoa(caracter1);
	 		 	char c2[2];
	 		 		  	c2[0] = caracter2 + '0';
	 		 		  	c2[1] = '\0';
	 		 		  	ST7735_WriteString(20, 15, c2, Font_16x26, BLACK, WHITE);
	 		 		  	HAL_Delay (1000);


	  }
	  botao11=lerbotao11;
	  while (botao11==0){
		  botao11=lerbotao11;
		  HAL_Delay(100);
	  }
	  botao11=lerbotao11;
	  while (botao11==1){//terceiro caracter
		  botao11=lerbotao11;
		  botao12=lerbotao12;
	 if (botao12==0 && caracter3<9){
		 caracter3++;
	 }
	 botao10=lerbotao10;
	  if (botao10==0){
		  botao10=lerbotao10;
		 caracter3--;

	 }

	 		  	  //char c = itoa(caracter1);
	 		 	char c3[2];
	 		 		  	c3[0] = caracter3 + '0';
	 		 		  	c3[1] = '\0';
	 		 		  	ST7735_WriteString(35, 15, c3, Font_16x26, BLACK, WHITE);
	 		 		  	HAL_Delay (1000);


	  }
	  botao11=lerbotao11;
	  while (botao11==0){
		  botao11=lerbotao11;
		  HAL_Delay(100);
	  }
	  botao11=lerbotao11;
	  while (botao11==1){ //quarto caracter
		  botao11=lerbotao11;
		  botao12=lerbotao12;
	 if (botao12==0 && caracter4<9){
		 botao12=lerbotao12;
		 caracter4++;
	 }
	 botao10=lerbotao10;
	  if (botao10==0){
		  botao10=lerbotao10;
		 caracter4--;
	 }

	 		  	  //char c = itoa(caracter1);
	 		 	char c4[2];
	 		 		  	c4[0] = caracter4 + '0';
	 		 		  	c4[1] = '\0';
	 		 		  	ST7735_WriteString(50, 15, c4, Font_16x26, BLACK, WHITE);
	 		 		  	HAL_Delay (1000);

	  }
	  botao11=lerbotao11;
	  while (botao11==0){
		  botao11=lerbotao11;
		  HAL_Delay(100);
	  }

	  senhadigitada= (caracter1*1000)+(caracter2*100)+(caracter3*10)+(caracter4);


		  	if(senhadigitada!=senha){
		  		tentativas++;
		  		ST7735_FillScreen(WHITE);
		  		ST7735_WriteString(10,30,"Senha Errada",Font_11x18,GREEN,WHITE);
		  		HAL_Delay(2000);
		  		if (tentativas >= 3){
		  			bloqueado = 1;
		  			tempoBloqueio = HAL_GetTick();

		  		}
		  	}


	  if (senhadigitada==senha){
		  senhacorreta=1;
		  ST7735_FillScreen(WHITE);
			               ST7735_WriteString(5,15, "Senha correta!!", Font_11x18,GREEN, WHITE);
					  	  HAL_Delay(2000);
					  	ST7735_FillScreen(WHITE);
		  ST7735_FillScreen(WHITE);
		               ST7735_WriteString(1,15, "Digite a quantidade de alunos max na sala", Font_7x10,GREEN, WHITE);
				  	  HAL_Delay(2000);
				  	ST7735_FillScreen(WHITE);
                       botao11=lerbotao11;
				  	 while (botao11==1){ //a quantidade de dezenas dos alunos.
				  		 botao11=lerbotao11;
				  		 botao12=lerbotao12;
				  		 if (botao12==0){
				  			 botao12=lerbotao12;
				  			 alunosD++;
				  		 }
				  		 botao10=lerbotao10;
				  		  if (botao10==0){
				  			  botao10=lerbotao10;
				  			 alunosD--;
				  		 }
				  		char cd[2];
				  			  	cd[0] = alunosD + '0';
				  			  	cd[1] = '\0';
				  			  	ST7735_WriteString(5, 15, cd, Font_16x26, BLACK, WHITE);
				  			  	HAL_Delay (1000);
				  	 }
				  	 botao11=lerbotao11;
				  	 while (botao11==0){
				  		 botao11=lerbotao11;
				  		 HAL_Delay(1000);
				  	 }
				  	 botao11=lerbotao11;
				  	 while (botao11==1){//a quantidade de unidades dos alunos.
				  		 botao11=lerbotao11;
				  		 botao12=lerbotao12;
				  	 if (botao12==0){
				  		 botao12=lerbotao12;
				  		alunosU++;
				  		}
				  	 botao10=lerbotao10;
				  	if (botao10==0){
				  		botao10=lerbotao10;
				  		alunosU--;
				  		}
				  	char cU[2];
				  	cU[0] = alunosU + '0';
				  	cU[1] = '\0';
				  	ST7735_WriteString(20, 15, cU, Font_16x26, BLACK, WHITE);
				  	HAL_Delay (1000);

				  		 }
				  	 botao11=lerbotao11;
				  	while (botao11==0){
				  		botao11=lerbotao11;
				  		HAL_Delay(1000);
				  	 }
				  int maxAlunos= (alunosD*10) + alunosU;
				  ST7735_FillScreen(WHITE);

 botao11=lerbotao11;
 botao12=lerbotao12;
				  while (botao11==1 || botao12==1 ){
					  botao11=lerbotao11;
					  botao12=lerbotao12;
						 char sal[10]={0};
						 sprintf(sal,"%d",alunos);
						 ST7735_WriteString(140,15, sal, Font_7x10,GREEN, WHITE);
						  ST7735_WriteString(1,15, "alunos presentes:", Font_7x10,GREEN, WHITE);

							char cf[2];
							cf[0] = alunosfora + '0';
							cf[1] = '\0';
							ST7735_WriteString(140, 40, cf, Font_7x10, BLACK, WHITE);
							ST7735_WriteString(1,40, "alunos fora da sala:", Font_7x10,GREEN, WHITE);
						  char cma[10];
						  sprintf(cma,"%d",maxAlunos);
						  ST7735_WriteString(140, 60, cma, Font_7x10, BLACK, WHITE);


						  atualizarBarra(alunos,maxAlunos);
						  HAL_Delay(2000);
					if (alunos<maxAlunos) {
						botao9=lerbotao9;
					  if (botao9==0){ // entradas dos alunos
                 botao9=lerbotao9;
						  alunos++;
						  atualizarBarra(alunos,maxAlunos);
						  alunosvieram++;
                 ST7735_FillScreen(WHITE);
                 ST7735_WriteString(1,15, "Scaneando aluno", Font_7x10,GREEN, WHITE);

                 HAL_Delay(2000);
                 ST7735_FillScreen(WHITE);
                 ST7735_WriteString(1,30, "Matricula", Font_7x10,GREEN, WHITE);
                 HAL_Delay(2000);


                 char mt[10]={0};
                 sprintf(mt,"%d",matricula);
                 ST7735_WriteString(70,30, mt, Font_7x10,GREEN, WHITE);
                 HAL_Delay(500);
                 ST7735_FillScreen(WHITE);


					  }
					  botao10=lerbotao10;
                 if (botao10==0){          //saidas de alunos
                	 botao10=lerbotao10;
                	 alunos--;
                	 atualizarBarra(alunos,maxAlunos);
                	 alunosvieram--;

                 }


					}
					botao11=lerbotao11;
					if (botao11==0){ //alunos sairam pro banheiro ou agua
						botao11=lerbotao11;
						alunosfora++;
						saidas++;
					}
					botao12=lerbotao12;
						if (botao12==0  && alunosfora>0){ //alunos voltaram do banheiro
							botao12=lerbotao12;
						alunosfora--;
					}


                     botao11=lerbotao11;
if (botao11==0 && alunosfora>3 ){
	  ST7735_FillScreen(WHITE);
	  ST7735_WriteString(1,15, "Quantidade de alunos     fora max", Font_7x10,YELLOW, WHITE);
	  HAL_Delay(2000);
	  ST7735_FillScreen(WHITE);
	  alunosfora=3;

}

				  }
				  botao11=lerbotao11;
				  botao12=lerbotao12;
				  if (botao11==0 && botao12==0){
					  botao11=lerbotao11;
					  botao12=lerbotao12;
					  ST7735_FillScreen(WHITE);

					  char cll[10];
					  cll[0] = saidas + '0';
					  cll[1] = '\0';
					  char cav[10];
					  cav[0] = alunosvieram + '0';
					  cav[1] = '\0';
					  ST7735_WriteString(125, 15, cll, Font_7x10, BLACK, WHITE);
					  ST7735_WriteString(1,15, "Saidas totais:", Font_7x10,YELLOW, WHITE);
					  ST7735_WriteString(125, 30, cav, Font_7x10, BLACK, WHITE);
					  ST7735_WriteString(1,30, "Alunos presentes:", Font_7x10,YELLOW, WHITE);

				  }


	  }
		  }








	                }
	  }
  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */


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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
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
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(ST7735_CS_GPIO_Port, ST7735_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ST7735_DC_Pin|ST7735_RES_Pin|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin : ST7735_CS_Pin */
  GPIO_InitStruct.Pin = ST7735_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ST7735_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ST7735_DC_Pin ST7735_RES_Pin PB3 PB4
                           PB5 PB6 */
  GPIO_InitStruct.Pin = ST7735_DC_Pin|ST7735_RES_Pin|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BOTAOPA9_Pin BOTAOPA10_Pin BOTAOPA11_Pin BOTAOPA12_Pin */
  GPIO_InitStruct.Pin = BOTAOPA9_Pin|BOTAOPA10_Pin|BOTAOPA11_Pin|BOTAOPA12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
