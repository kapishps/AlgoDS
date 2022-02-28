class ParkingSystem {
public:
    int m[4];
    ParkingSystem(int big, int medium, int small) {
        m[1] = big;
        m[2] = medium;
        m[3] = small;
    }
    
    bool addCar(int carType) {
        m[carType]--;
        return m[carType] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */