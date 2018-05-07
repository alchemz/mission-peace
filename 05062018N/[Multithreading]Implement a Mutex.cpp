//---------------->Mutex.h
class Mutex
{
public:
        Mutex();
        ~Mutex();
        void        lock();
        void        unlock();
        boolean     isLocked();

protected:
        uint8_t     _interlockedExchange(uint8_t v);

private:
        uint8_t     m_count;
};

Mutex::Mutex()
{
    //ctor
    m_count = 1;
}

//------------->Mutex.cpp
Mutex::~Mutex()
{
    //dtor
}

uint8_t Mutex::_interlockedExchange(uint8_t v)
{
    uint8_t ov = m_count;
    m_count = v;

    return (ov);
}

void Mutex::lock()
{
    uint8_t prev;

    while(1)
    {
        while (m_count == 0) { };

        prev = _interlockedExchange(0);

        if (prev == 1)
            break;
    }
}

void Mutex::unlock()
{
    (void) _interlockedExchange(1);
}


boolean Mutex::isLocked()
{
    if (m_count == 0)
        return (true);

    return (false);
}

//----------->sketch

Mutex mutex;

void setup()
{
    // initialize the digital pin as an output.
    // Pin 13 has an LED connected on most Arduino boards:
    pinMode(13, OUTPUT);
}

void loop()
{
    mutex.lock();
    digitalWrite(13, HIGH);   // set the LED on
    mutex.unlock();
    delay(1000);              // wait for a second
    mutex.lock();
    digitalWrite(13, LOW);    // set the LED off
    mutex.unlock();
    delay(1000);              // wait for a second
}

//https://github.com/f1rmb/Mutex
/*
Mutex:
void lock();
bool unlock();

SharedMutex:
void readerLock();
void readerUnlock();
void writerLock();
void writerUnlock();
*/