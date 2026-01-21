#pragma once

#include "orientedComponent.hpp"
#include "../model/boundedRangeModel.hpp"

class Gauge : public OrientedComponent{

private:
    BoundedRangeModel& rangeModel;

    Color barColor = YELLOW;

public:
    Gauge(BoundedRangeModel& boundedRangeModel);

    BoundedRangeModel& getBoundedRangeModel() const;
    void setBoundedRangeModel(BoundedRangeModel& model);

    void SetBarColor(Color color);

    virtual void draw() const override;
    virtual void fit() override;

    virtual void toStr(std::ostream& stream) const override;

};