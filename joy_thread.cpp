#include "joy_thread.h"

Joy_Thread::Joy_Thread(QObject *parent) :
    QThread(parent)
{
}

//发送joy的状态结构体信号
void Joy_Thread::send_state_row(joyinfoex_tag state_row)
{
    emit JoySignal_row(state_row);
}

//Joy_Thread的线程主体
void Joy_Thread::run()
{
    joyinfoex_tag state_row;

    openJoy();

    while(1) {
        msleep(JOY_READ_PEROID);
        state_row = joyRead_row();
        send_state_row(state_row);
    }
}

