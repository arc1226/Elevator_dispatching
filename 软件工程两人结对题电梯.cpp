#include <iostream>
#include <vector>

using namespace std;

// ����״̬ö������
enum ElevatorState {
    Idle,
    Up,
    Down,
};

// ������
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
    int id_;                // ���ݱ��
    int maxFloor_;          // �ɷ�������¥��
    int maxPassenger_;      // ���˿�����
    int maxWeight_;         // ���������
    ElevatorState state_;   // ��ǰ״̬������/����/���У�
    int curFloor_;          // ��ǰ����¥��
};

// ������
class Request {
public:
    Request(int floor, ElevatorState state) : floor_(floor), state_(state) {}
    int getFloor() const { return floor_; }
    ElevatorState getState() const { return state_; }

private:
    int floor_;             // ����¥��
    ElevatorState state_;   // ����������/���У�
};

int main() {
    // ��ʼ������
    vector<Elevator> elevators;
    elevators.push_back(Elevator(1, 21, 10, 800));
    elevators.push_back(Elevator(2, 1, 10, 800));
    elevators.push_back(Elevator(3, 2, 10, 800));
    elevators.push_back(Elevator(4, 21, 10, 2000));

    // ��ʼ��������
    while (true) {
        int floor;
        string direction;
        cout << "����������¥��ͷ���up/down����" << endl;
        cin >> floor >> direction;

        // ����������
        ElevatorState requestState = Idle;
        if (direction == "up") {
            requestState = Up;
        }
        else if (direction == "down") {
            requestState = Down;
        }
        else {
            cout << "����ķ������������룡" << endl;
            continue;
        }

        // ������ѵ���
        int bestElevator = -1;
        int minTime = INT_MAX;
        for (int i = 0; i < elevators.size(); ++i) {
            // �������Ƿ�ɷ����¥��
            if (elevators[i].getMaxFloor() < floor) {
                continue;
            }

            // ������ݵ����¥���ʱ��
            int time = abs(elevators[i].getCurFloor() - floor);
            if (elevators[i].getState() == Idle) {
                time *= 2;      // ����ǿ���״̬������Ҫ����2
            }
            if (elevators[i].getState() != requestState) {
                time += elevators[i].getMaxFloor();    // �����������ͬ������Ҫ����������¥����
            }
            if (time < minTime) {
                bestElevator = i;
                minTime = time;
            }
        }

        // û�п��õ���
        if (bestElevator == -1) {
            cout << "û�п��õ��ݣ����������룡" << endl;
            continue;
        }

        // ���µ���״̬�͵�ǰ¥��
        elevators[bestElevator].setState(requestState);
        elevators[bestElevator].setCurFloor(floor);

        // ���������Ϣ
        cout << "����" << elevators[bestElevator].getId() << "�ѽ�������" << endl;
        cout << "��ǰ״̬Ϊ��";
        if (requestState == Up) {
            cout << "����" << endl;
        }
        else {
            cout << "����" << endl;
        }
        cout << "��ǰ����¥��Ϊ��" << floor << endl;
    }

    return 0;
}