/*
 * IoHarbour.cpp
 *
 *  Created on: May 11, 2014
 *      Author: Adam Kosiorek
 */

#include "IoHarbour.h"

namespace ships {

IoHarbour::IoHarbour()
	: work_(new io_service::work(ioService_)) {}

IoHarbour::~IoHarbour() {
	// TODO Auto-generated destructor stub
}

io_service& IoHarbour::getService() {

	return ioService_;
}

void IoHarbour::run() {
	ioService_.run();
}

void IoHarbour::poll() {
	ioService_.poll();
}

void IoHarbour::dispatch(std::function<void()> fun) {
	ioService_.dispatch(fun);
}

void IoHarbour::post(std::function<void()> fun) {
	ioService_.post(fun);
}

} /* namespace ships */

bool ships::IoHarbour::hasStopped() {
	return ioService_.stopped();
}

void ships::IoHarbour::stop() {
	work_.reset();
	ioService_.stop();
}

void ships::IoHarbour::reset() {
	ioService_.reset();
}
