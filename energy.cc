double calculateEnergy(EnergySourceContainer sources, uint32_t nNodes) {
    double remainingEnergy = 0.0;

    for (auto src = sources.Begin(); src != sources.End(); ++src) {
        remainingEnergy += (*src)->GetRemainingEnergy();
    }

    return nNodes * 100.0 - remainingEnergy;
}
