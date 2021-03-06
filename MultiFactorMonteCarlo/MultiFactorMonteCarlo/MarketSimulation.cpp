//
//  MarketSimulation.cpp
//  MultiFactorMonteCarlo
//
//  Created by Peter Benson on 10/25/16.
//  Copyright © 2016 Peter Benson. All rights reserved.
//
#include <random>

#include "MarketSimulation.hpp"

std::default_random_engine MarketSimulation::generator;
std::normal_distribution<double> MarketSimulation::standardNormalDistribution(0, 1);

MarketSimulation::MarketSimulation(int size):m_weights(size) {
    for(int i = 0; i < size; ++i) {
        m_weights[i] = standardNormalDistribution(generator);
    }
}

const std::vector<double>& MarketSimulation::weights() const {
    return m_weights;
}

void MarketSimulation::resetSeed() {
    generator.seed(generator.default_seed);
}
