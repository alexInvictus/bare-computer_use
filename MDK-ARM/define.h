#ifndef _H_DEFINE_
#define _H_DEFINE_
//=====================================================
//                串口接收的数组大小的定义
//=====================================================
#define USART_REC_LEN_1       200          //最大接收字节
#define USART_REC_LEN_2       200          //最大接收字节
#define USART_REC_LEN_3       200          //最大接收字节
#define RXBUFFERSIZE           1           //接受字节数（中间）
//=====================================================
//                 按键定义、报警定义
//=====================================================
#define Key_Start         0       //HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2)
#define Key_Stop          0       //HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3)
#define protect_ahead     HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_14)
#define protect_back      HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)
//=====================================================
//                 红外传感器的引脚定义
//=====================================================
#define Ahead_Senor_1   HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0)
#define Ahead_Senor_2   HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1)
#define Ahead_Senor_3   HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)
#define Ahead_Senor_4   HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)
#define Ahead_Senor_5   HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)

#define Back_Senor_1   HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2)
#define Back_Senor_2   HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3)
#define Back_Senor_3   HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4)
#define Back_Senor_4   HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5)
#define Back_Senor_5   HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_6)
//=====================================================
//                 ADC地址
//=====================================================
#define ADC1_DR_Address    ((u32)0x4001244C)
#define LCD_CMD            (u32)0xf8000000 						//
#define LCD_DATE           (u32)0xfa000000 						//
//=====================================================
//                 128*64的显示屏的行首地址
//=====================================================
#define Line1   0x83
#define Line5   0x83
#define Line2   0x92
#define Line3   0x89
#define Line4   0x98
//=====================================================
//                 显示屏操作的4个口
//=====================================================
#define CS_H HAL_GPIO_WritePin(GPIOH,GPIO_PIN_13,GPIO_PIN_SET) 			//RS=1   4PIN
#define CS_L HAL_GPIO_WritePin(GPIOH,GPIO_PIN_13,GPIO_PIN_RESET) 			//RS=0 

#define RW_H HAL_GPIO_WritePin(GPIOH,GPIO_PIN_14,GPIO_PIN_SET)  			//RW=1    5PIN
#define RW_L HAL_GPIO_WritePin(GPIOH,GPIO_PIN_14,GPIO_PIN_RESET)   			//RW = 0

#define CLK_H HAL_GPIO_WritePin(GPIOH,GPIO_PIN_15,GPIO_PIN_SET)  			//RW=1    5PIN
#define CLK_L HAL_GPIO_WritePin(GPIOH,GPIO_PIN_15,GPIO_PIN_RESET)   		//RW = 0

#define RST_H HAL_GPIO_WritePin(GPIOI,GPIO_PIN_8,GPIO_PIN_SET)  			//RW=1    5PIN
#define RST_L HAL_GPIO_WritePin(GPIOI,GPIO_PIN_8,GPIO_PIN_RESET)     		//RW = 0
//=====================================================
//                 转弯延迟的时间
//=====================================================
#define Turn_time   6500         //6500毫秒
#define TEST_TIM    65000        //65000次检测到就停止
//=====================================================
//                 motor
//=====================================================
#define ULTRA_NUM 2
//=====================================================
//                 LED的操作
//=====================================================
#define LED_ON  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_13,GPIO_PIN_SET) 			  //开启LED灯
#define LED_OFF HAL_GPIO_WritePin(GPIOA,GPIO_PIN_13,GPIO_PIN_RESET) 			//关闭LED灯 
//=====================================================
//                 函数声明
//=====================================================
void Error_Handler(void);
void MX_GPIO_Init(void);                        //gpio口初始化配置 
void MX_TIM13_Init(void);                       //定时器13初始化配置产生PWM波
void MX_TIM14_Init(void);                       //定时器14初始化配置产生PWM波
void MX_TIM3_Init(void);
void SystemClock_Config(void);                  //时钟的配置
void MX_USART1_UART_Init(void);                 //串口1初始化
void MX_USART2_UART_Init(void);                 //串口2初始化
void MX_USART3_UART_Init(void);                 //串口3初始化
void MX_ADC1_Init(void);
void MX_NVIC_Init(void);
void MX_DMA_Init(void);
void Uart_test(void);                           //串口测试程序
int Uart_Store(void);                           //串口转存
void Uart_Analyse(void);                        //分析轨道 分数组存到相应的二维数组
void Eeprom_Read(void);                         //读取eeprom里面的车号
void Send_Id(void);                             //发送id号给中控系统
void Write_id(void);
/*电机的操作的相关函数*/
void Motor_Ahead_Wait(void);                    //前进到取料点模式
void Motor_Ahead(void);                         //前进模式
void Motor_Back(void);                          //后退模式
void Motor_Ruku(void);                          //后退模式--直接去起始点
void Ahead_Trailing(void);                      //前进循迹走
void Back_Trailing(void);                       //后退循迹走
void Answer(void);                              //找到之后报给中控
void Find_Rfid(void);                           //寻找RFID卡
void Find_Rfid_Match(void);                     //匹配RFID的函数
void Stop(void);                                //停止
void Set_Motor(int left,int right);             //设置电机的速度
void free_array(void);                          //释放数组内存的函数
void Set_Acc(int target);                       //加速设置函数 target为目标速度
void Set_Slowdown(int target);                  //减速设置函数 target为目标速度
void ahead_wave(void);
void back_wave(void);
/*显示屏的操作的函数*/
void LCD_init(void);
void Display(u8 addr,u8 *hz);
void LCD_Write(u32 cmd,u8 ddata);
void Show_Static(void);
void Voltage_Test(void); 
uint16_t ADC_Average(uint16_t *buff,uint16_t num,uint16_t threshold);    //ADC采集滤波函数

#endif


