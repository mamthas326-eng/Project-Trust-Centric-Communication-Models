bool isTrusted(uint32_t src, uint32_t dst, uint32_t maliciousNode) {
    if (src == maliciousNode || dst == maliciousNode)
        return false;
    return true;
}
bool shouldDropPacket() {
    return (rand() % 20 < 1); // 10% drop
}
