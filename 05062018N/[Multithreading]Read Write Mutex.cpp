class ReadWriteMutex {
        int reader = 0;
        Mutex mutex = new Mutex();
        Mutex readerCountMutex = new Mutex();

        void readLock() {
                readerCountMutex.lock();
                if (reader == 0) {
                        mutex.lock();
                }
                reader++;
                readerCountMutex.unlock();
        }

        void readUnlock() {. From 1point 3acres bbs
                readerCountMutex.lock();. 1point3acres.com/bbs
                reader--;
                if (reader == 0) {
                        mutex.unlock();
                }
                readerCountMutex.unlock();
        }

        void writeLock () {
                mutex.lock();
        }

        void writeUnlock() {
                mutex.unlock();
        }
}
//http://www.drdobbs.com/cc-tip-8-performing-multiple-readwrite-l/184401515
//https://www.codeproject.com/Articles/16411/Ultra-simple-C-Read-Write-Lock-Class-for-Windows