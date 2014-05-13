/*
 * BigGameShip.h
 *
 *  Created on: May 11, 2014
 *      Author: paulina
 */

#ifndef BIGGAMESHIP_H_
#define BIGGAMESHIP_H_

#include "GameShip.h"
#include "HitObserver.h"
#include "hitShip_typedef.h"
#include <vector>

class BigGameShip: public GameShip {

public:
	BigGameShip();
	virtual ~BigGameShip();
	using GameShip::ShipState;

	typedef std::shared_ptr<GameShip> ShipPtr;

	SignalShipType hitShip;
	void registerShipObserver(ShipObserverPtr shipObserver);

	virtual void hit() override;

	virtual ShipState getState() const override;
	virtual std::size_t getSize() const override;

	void addShip(ShipPtr ship);
	void addShips(std::vector<ShipPtr> ships);

private:
	std::vector<ShipPtr> ships_;
};

#endif /* BIGGAMESHIP_H_ */