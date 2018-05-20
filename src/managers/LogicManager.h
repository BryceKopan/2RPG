#ifndef LOGICMANAGER_H
#define LOGICMANAGER_H

class LogicManager
{
    public:
        static void initialize();
        static void update();

    private:
        static double lastFrameTime;
};

#endif

