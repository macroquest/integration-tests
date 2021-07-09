<br/>

# MQNext Test Suite
Macroquest Next Integration Tests

<br/>

## Features
- Tests written in fun and easy to use Lua programming language
- Simple to use Testing Framework based on [u-test](https://github.com/IUdalov/u-test)
- Tests broken out by Top Level Objects for easy problem identification
- TLOs that expose multiple DataTypes seperated into individual Test suites

<br/>

## Getting Started
- Clone the project in your MQNext lua folder (this will create a subfolder called "TestSuite")
- All tests (so far) are based on a Heroic level 85 Male Troll Shadow Knight
- Do not self-buff
- Do not click on any "clickie" eqiupment
- Be wary of areas where you may be inadverantly buffed while running tests
- Park the SK in a safe spot away from large crowds

<br/>

## Run your tests

All commands are ran from the MQNext Console
- Ensure the MQ2Lua Plugin is installed


```
/plugin mq2lua load
```

- Test the "Me" TLO
```
/lua run TestSuite/Me-TLO
```

- Test only members that contain the word 'combat'
```
/lua run TestSuite/Me combat
```

- You should see output like this:

![Example Output](/images/testSuite_example_run.png)


## Feedback 
Any questions or suggestions?

You are welcome to discuss it on our [Discord Channel](https://discord.gg/gKktV3DY6M)

<br/>