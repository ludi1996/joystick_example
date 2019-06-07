#ifndef JOY_THREAD_H
#define JOY_THREAD_H

#include <QThread>
//#include <QDebug>
#include "joystick.h"

#define JOY_READ_PEROID  100 //读取手柄周期,单位ms

class Joy_Thread : public QThread
{
    Q_OBJECT
public:
    explicit Joy_Thread(QObject *parent = 0);

signals:
    void JoySignal_row(joyinfoex_tag);

protected:
    void run();
    void send_state_row(joyinfoex_tag state_row);

};

#endif // JOY_THREAD_H
