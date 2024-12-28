#include <iostream>

int main() {
    int GENERAL_DISPERSER_GAS_FLOW = 1280;
    int GENERAL_VENT_GAS_FLOW = 32000;
    int TURBINE_DISPERSER_COUNT = 540;
    int TURBINE_VENT_COUNT = 340;
    int TURBINE_SIDE_LENGTH = 15;
    int ROTOR_CHAMBER_HEIGHT = 14;
    double TURBINE_STORED_AMOUNT = 10000000;
    double TURBINE_MAX_STORED_AMOUNT = 258944000;

    int DISPERSER_FLOW = TURBINE_DISPERSER_COUNT * GENERAL_DISPERSER_GAS_FLOW * (TURBINE_SIDE_LENGTH^2 * ROTOR_CHAMBER_HEIGHT);
    int VENT_FLOW = TURBINE_VENT_COUNT * GENERAL_VENT_GAS_FLOW;

    int MAX_RATE = std::min(DISPERSER_FLOW, VENT_FLOW);

    double fill_ratio = TURBINE_STORED_AMOUNT / MAX_RATE;
    double steam_flow = TURBINE_STORED_AMOUNT / TURBINE_MAX_STORED_AMOUNT;

    double FLOW = std::min(1.0, fill_ratio) * steam_flow * MAX_RATE;
    
    printf("Disperser flow rate: %d\nVent flow rate: %d\nMax Rate: %d\nFlow rate: %f\n", DISPERSER_FLOW, VENT_FLOW, MAX_RATE, FLOW);

    printf("Energy production: %.2fRF/t\n", (FLOW * ROTOR_CHAMBER_HEIGHT * 50)/7);
}