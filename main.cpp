#include "mbed.h"

void i2c_master()
{
    I2C i2c(PF_0, PF_1); 

    char data[16];
    int i = 0;

    while (1)
    {
        snprintf(data, 16, "Hello World %d", i);
        i2c.write(0x82, data, 16);

        i = (i + 1) % 1000;
    }
}


void i2c_slave()
{
    I2CSlave i2c(PD_13, PD_12);
    i2c.address(0x82);
    char data[16];
    while (1)
    {
        if (i2c.receive() == I2CSlave::WriteAddressed)
        {
            memset(data, 0, 16);
            int count = i2c.read(data, 16);
            printf("%d %.16s\n", count, data);
        }
    }
}


static Thread MASTER_THREAD(osPriorityNormal, OS_STACK_SIZE, nullptr, "Master Thread");
static Thread SLAVE_THREAD(osPriorityNormal, OS_STACK_SIZE, nullptr, "Slave Thread");

int main()
{
    printf("Hello, Mbed!\n");
    SLAVE_THREAD.start(i2c_slave);
    MASTER_THREAD.start(i2c_master);
    return 0;
}
