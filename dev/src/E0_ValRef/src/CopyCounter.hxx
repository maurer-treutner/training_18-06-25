#ifndef __COPYCOUNTER_HXX__
#define __COPYCOUNTER_HXX__

class CopyCounter
{
public:
    CopyCounter()
    {
        ++_defaultCCounter;
    }

    CopyCounter(int i):
        _i(i)
    {
        ++_defaultCCounter;
    }

    CopyCounter(const CopyCounter&)
    {
        ++_copyCCounter;
    }

    ~CopyCounter()
    {
        ++_dctorCCounter;
    }

    const CopyCounter& operator = (const CopyCounter&)
    {
        ++_copyOpCounter;
        return *this;
    }

    static void clearCounters()
    {
        _defaultCCounter=0;
        _copyCCounter=0;
        _copyOpCounter=0;
        _dctorCCounter=0;
    }

    static void printCounters(const std::string& info)
    {
        std::cout<<info<<std::endl;
        std::cout<<"dctor: "<<_defaultCCounter<<"\tcctor: "<<_copyCCounter<<"\tcop: "<<_copyOpCounter<<"\tdctor: "<<_dctorCCounter<<std::endl;
    }

    void doSmt()
    {
        ++_i;
    }

private:
    static int _defaultCCounter;
    static int _copyCCounter;
    static int _copyOpCounter;
    static int _dctorCCounter;

    int _i=0;

};

int CopyCounter::_defaultCCounter = 0;
int CopyCounter::_copyCCounter = 0;
int CopyCounter::_copyOpCounter = 0;
int CopyCounter::_dctorCCounter = 0;

#endif