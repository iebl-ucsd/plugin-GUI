#include "BroadcastPayload.h"

BroadcastPayload::BroadcastPayload(String command, DynamicObject::Ptr payload) : _commandName(command), _payload(payload) {}

String BroadcastPayload::getCommandName() const {
	return _commandName;
}

bool BroadcastPayload::getIntField(String name, int& value, int lowerBound, int upperBound) {
    if (!_payload->hasProperty(name) || !_payload->getProperty(name).isInt())
        return false;
    int tempVal = _payload->getProperty(name);
    if ((upperBound != INT_MIN && tempVal > upperBound) || (lowerBound != INT_MAX && tempVal < lowerBound))
        return false;
    value = tempVal;
    return true;
}