#include "gtest/gtest.h"

#include <JuceHeader.h>

class MockChangeListener : public ChangeListener
{
public:
    // Inherited via ChangeListener
    void changeListenerCallback (ChangeBroadcaster* source) override
    {
        ++numCalls;
    }

public:
    int numCalls = 0;
};

class ChangeListenerUnitTests : public testing::Test
{
protected:
    MockChangeListener listener;
};

TEST_F (ChangeListenerUnitTests, ChangeListenerCallback)
{
    listener.changeListenerCallback (nullptr);

    EXPECT_EQ (listener.numCalls, 1);
}