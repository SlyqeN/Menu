#ifndef ABSTRACTDEPOSITCONTAINER_H
#define ABSTRACTDEPOSITCONTAINER_H
#include "../Models/Deposit/Deposit.h"
using namespace std;

class AbstractDepositContainer {
public:
    virtual ~AbstractDepositContainer() = default;
    virtual bool addDeposit(const Deposit& deposit) = 0;
    virtual int getDepositCount() const = 0;
    virtual const Deposit* getDeposits() const = 0;
};

#endif // ABSTRACTDEPOSITCONTAINER_H 