#include "joystick.h"
#include <QMessageBox>
#include <QDebug>

static joyinfoex_tag     now_act;

//加载多媒体库
QLibrary mylib("Winmm.dll");
//解析游戏杆捕获函数joySetCapture
MyPrototype qJoySetCapture = (MyPrototype)mylib.resolve("joySetCapture");
//游戏杆数获得函数
MyPrototype1 qJoyReleaseCapture = (MyPrototype1)mylib.resolve("joyReleaseCapture");
//返回游戏杆位置及按钮活动函数
MyPrototype2 qJoyGetPosEx = (MyPrototype2)mylib.resolve("joyGetPosEx");
//返回游戏杆位置及按钮活动函数
MyPrototype0 qJoyGetPos = (MyPrototype0)mylib.resolve("joyGetPos");
//读取操纵杆移动阈值
MyPrototype3 qJoyGetThreshold = (MyPrototype3)mylib.resolve("joyGetThreshold");
//获取操纵杆属性信息，以结构体JoyCaps接收
MyPrototype4 qJoyGetDevCaps = (MyPrototype4)mylib.resolve("joyGetDevCapsW");
//有多少个游戏杆可以用
MyPrototype5 qJoyGetNumDevs = (MyPrototype5)mylib.resolve("joyGetNumDevs");

//打开手柄，开启对手柄的检测功能
void openJoy()
{
    JOYCAPS joycaps;
    qJoyGetDevCaps(JSX, &joycaps, sizeof(joycaps));
}

//轮询检测手柄按键函数
struct joyinfoex_tag joyRead_row()
{
    now_act.dwSize = sizeof(typeof(joyinfoex_tag));
    now_act.dwFlags = (int)JOY_RETURNBUTTONS;
    qJoyGetPosEx(JSX, &now_act);

    return now_act;
}
