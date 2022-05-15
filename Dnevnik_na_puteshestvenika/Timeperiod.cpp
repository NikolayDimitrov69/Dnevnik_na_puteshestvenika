#include <iostream>
#include "Timeperiod.h"

bool validateTimeperiod(Timeperiod& _period) {
    bool instance_1 = _period.getStartYear() > _period.getEndYear();
    bool instance_2 = _period.getStartYear() == _period.getEndYear() && _period.getStartMonth() > _period.getEndMonth();
    bool instance_3 = _period.getEndMonth() == _period.getStartMonth() && _period.getStartDay() > _period.getEndDay();
    if (instance_1 || instance_2 || instance_3)
    {
        std::cout << "Invalid time period.\n";
        return false;
    }
    else
    {
        return true;
    }
}

Timeperiod::Timeperiod() 
{}

Timeperiod::Timeperiod(Date _start, Date _end)
	:start(_start),
	end(_end) 
{}


std::istream& operator >> (std::istream& is, Timeperiod& period) {	
    Timeperiod _period;

    if (is.rdbuf() == std::cin.rdbuf())
    {  
        do {
            std::cout << "Enter start date: ";
            is >> _period.start;
            std::cout << "Enter end date: ";
            is >> _period.end;
        } while (!validateTimeperiod(_period));
    }
    else
    {
        is >> _period.start >> _period.end;
    }

    period = Timeperiod(_period);

    return is;
}

std::ostream& operator << (std::ostream & os, const Timeperiod & period) {
        if (os.rdbuf() == std::cout.rdbuf())
        {
            os << "Start date: " << period.start << " End date: " << period.end;
        }
        else
        {
            os << period.start << ' ' << period.end;
        }
        return os;
    }



