#ifndef __DATA_MOTHER_H__
#define __DATA_MOTHER_H__
#include "actor.h"
struct DummyActor : Actor
{
    DummyActor() : m_count(0)
    {

    }
    int msg_received(const char *msg, int len)
    {
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
            m_count = sequence;
            if (m_count % 100 == 0)
            {
                std::cout << "msg_received count: " << m_count << std::endl;
            }
        }
        else
        {
            std::cout << "error, unexpected length received:" << std::endl;
        }
        return 0;
    }
    int m_count;
};
#endif