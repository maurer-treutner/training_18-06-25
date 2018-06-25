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

    CopyCounter(CopyCounter&& rhs)
    {
        ++_moveCCounter;
        std::swap(_i,rhs._i);
    }

    ~CopyCounter()
    {
        ++_dctorCounter;
    }

    const CopyCounter& operator = (const CopyCounter& rhs)
    {
        ++_copyOpCounter;
        return *this;
        _i = rhs._i;
    }

    const CopyCounter& operator = (CopyCounter&& rhs)
    {
        ++_moveOpCounter;
        std::swap(_i,rhs._i);
    }

    static void clearCounters()
    {
        _defaultCCounter=0;
        _copyCCounter=0;
        _moveCCounter=0;
        _copyOpCounter=0;
        _moveOpCounter=0;
        _dctorCounter=0;

    }

    static void printCounters(const std::string& info)
    {
        std::cout<<info<<std::endl;
        std::cout<<"dctor: "<<_defaultCCounter<<"\tcctor: "<<_copyCCounter<<"\tcop: "<<_copyOpCounter
            <<"\tmctor: "<<_moveCCounter<<"\tmov: "<<_moveOpCounter<<"\tdtor: "<<_dctorCounter<<std::endl;
    }

    void doSmt()
    {
        ++_i;
    }

    auto getI()
    {
        return _i;
    }

private:
    static int _defaultCCounter;
    static int _copyCCounter;
    static int _moveCCounter;
    static int _copyOpCounter;
    static int _moveOpCounter;
    static int _dctorCounter;

    int _i=0;

};

int CopyCounter::_defaultCCounter = 0;
int CopyCounter::_copyCCounter = 0;
int CopyCounter::_moveCCounter = 0;
int CopyCounter::_copyOpCounter = 0;
int CopyCounter::_moveOpCounter = 0;
int CopyCounter::_dctorCounter = 0;

#endif