double calculatePDR(uint32_t received, uint32_t sent) {
    return (double)received / sent * 100.0;
}

double calculateLoss(double pdr) {
    return 100.0 - pdr;
}

double calculateThroughput(uint32_t received, double simTime) {
    return (received * 512 * 8) / (simTime * 1000.0);
}
