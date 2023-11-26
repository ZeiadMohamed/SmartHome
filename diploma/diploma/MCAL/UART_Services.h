

#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_


void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);

void UART_SendStringCheckSum(u8*str);
u8 UART_ReceiveStringCheckSum(u8*str);


void UART_SendStringAshync(u8*str);

#endif /* UART_SERVICES_H_ */