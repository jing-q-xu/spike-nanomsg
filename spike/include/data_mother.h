#ifndef __DATA_MOTHER_H__
#define __DATA_MOTHER_H__
#include <sys/time.h>
#include "actor.h"
#include "msg.h"
namespace
{
const int BULK_MSG_COUNT = 1000000;
struct timeval get_current_time()
{
    struct timeval tv;
    gettimeofday (&tv, NULL);
    return tv;
    // return (((uint64_t)tv.tv_sec * 1000) + ((uint64_t)tv.tv_usec / 1000));
}

bool is_early(struct timeval &past, struct timeval &current)
{
    if (current.tv_sec < past.tv_sec)
    {
        return false;
    }
    if (current.tv_sec > past.tv_sec)
    {
        return true;
    }
    return current.tv_usec > past.tv_usec;
}

int get_mill_seconds_elapsed(struct timeval &past, struct timeval &current)
{
    if (!is_early(past, current))
    {
        return -1;
    }
    int result = (current.tv_sec - past.tv_sec) * 1000000;
    result += current.tv_usec;
    result -= past.tv_usec;
    return result;
}

int mill_seconds_elapsed(struct timeval &past)
{
    struct timeval current;
    gettimeofday (&current, NULL);
    return get_mill_seconds_elapsed(past, current);
}

}
struct DummyActor : Actor
{
    DummyActor() : m_count(-1), m_msg_count(0), m_first(0), m_last(BULK_MSG_COUNT)
    {
        m_start = get_current_time();
    }
    int msg_received(const char *msg, int len)
    {
        if (m_count == -1)
        {
            m_start = get_current_time();
        }
        if(len == sizeof(Greeting))
        {
            const Greeting* greet = (const Greeting*)msg;
            int sequence = greet->count;
            if(m_count != -1)
            {
                if(m_count + 1 != sequence)
                {
                    std::cout << "error, expect:" << m_count + 1 << " received:" << sequence << std::endl;
                }
            }
            else
            {
                m_first = sequence;
                m_last = sequence + BULK_MSG_COUNT - 1;
            }
            
            m_count = sequence;
            m_msg_count++;
            if (m_count % 10000 == 0)
            {
                std::cout << "msg_received count: " << m_count << std::endl;
            }
        }
        else
        {
            std::cout << "error, unexpected length received:" << std::endl;
        }
        if (m_count >= m_last)
        {
            int period = mill_seconds_elapsed(m_start);
            std::cout << "test finished, time: " << period << " useconds " << "actually received: " << m_msg_count << std::endl;
            return -1;
        }
        return 0;
    }
private:
    int m_count;
    int m_msg_count;
    int m_first;
    int m_last;
    struct timeval m_start;
};
#endif