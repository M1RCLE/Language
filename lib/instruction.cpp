static long operationSequence = 0;

long nextOperationId() {
    return ++operationSequence;
}