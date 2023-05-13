#include <iostream>
#include <vector>

using namespace std;

// 电梯状态枚举类型
enum ElevatorState {
    Idle,
    Up,
    Down,
};

// 电梯类
class Elevator {
public:
    Elevator(int id, int maxFloor, int maxPassenger, int maxWeight) :
        id_(id), maxFloor_(maxFloor), maxPassenger_(maxPassenger), maxWeight_(maxWeight), state_(Idle), curFloor_(0) {}
    int getId() const { return id_; }
    int getMaxFloor() const { return maxFloor_; }
    int getMaxPassenger() const { return maxPassenger_; }
    int getMaxWeight() const { return maxWeight_; }
    ElevatorState getState() const { return state_; }
    int getCurFloor() const { return curFloor_; }
    void setState(ElevatorState state) { state_ = state; }
    void setCurFloor(int floor) { curFloor_ = floor; }

private:
    int id_;                // 电梯编号
    int maxFloor_;          // 可服务的最高楼层
    int maxPassenger_;      // 最大乘客数量
    int maxWeight_;         // 最大载重量
    ElevatorState state_;   // 当前状态（空闲/上行/下行）
    int curFloor_;          // 当前所在楼层
};

// 请求类
class Request {
public:
    Request(int floor, ElevatorState state) : floor_(floor), state_(state) {}
    int getFloor() const { return floor_; }
    ElevatorState getState() const { return state_; }

private:
    int floor_;             // 请求楼层
    ElevatorState state_;   // 请求方向（上行/下行）
};

int main() {
    // 初始化电梯
    vector<Elevator> elevators;
    elevators.push_back(Elevator(1, 21, 10, 800));
    elevators.push_back(Elevator(2, 1, 10, 800));
    elevators.push_back(Elevator(3, 2, 10, 800));
    elevators.push_back(Elevator(4, 21, 10, 2000));

    // 开始接受请求
    while (true) {
        int floor;
        string direction;
        cout << "请输入请求楼层和方向（up/down）：" << endl;
        cin >> floor >> direction;

        // 解析请求方向
        ElevatorState requestState = Idle;
        if (direction == "up") {
            requestState = Up;
        }
        else if (direction == "down") {
            requestState = Down;
        }
        else {
            cout << "错误的方向，请重新输入！" << endl;
            continue;
        }

        // 查找最佳电梯
        int bestElevator = -1;
        int minTime = INT_MAX;
        for (int i = 0; i < elevators.size(); ++i) {
            // 检查电梯是否可服务该楼层
            if (elevators[i].getMaxFloor() < floor) {
                continue;
            }

            // 计算电梯到达该楼层的时间
            int time = abs(elevators[i].getCurFloor() - floor);
            if (elevators[i].getState() == Idle) {
                time *= 2;      // 如果是空闲状态，则需要乘以2
            }
            if (elevators[i].getState() != requestState) {
                time += elevators[i].getMaxFloor();    // 如果与请求方向不同，则需要加上最大服务楼层数
            }
            if (time < minTime) {
                bestElevator = i;
                minTime = time;
            }
        }

        // 没有可用电梯
        if (bestElevator == -1) {
            cout << "没有可用电梯，请重新输入！" << endl;
            continue;
        }

        // 更新电梯状态和当前楼层
        elevators[bestElevator].setState(requestState);
        elevators[bestElevator].setCurFloor(floor);

        // 输出电梯信息
        cout << "电梯" << elevators[bestElevator].getId() << "已接受请求！" << endl;
        cout << "当前状态为：";
        if (requestState == Up) {
            cout << "上行" << endl;
        }
        else {
            cout << "下行" << endl;
        }
        cout << "当前所在楼层为：" << floor << endl;
    }

    return 0;
}