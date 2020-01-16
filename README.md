place all files in macros\testsuite
execute test.mac 

assumptions
- you need to be in a guild hall

pass = member returned the expeted value/data type
fail = member did not return the expected value/data type
incomplete = unable to test for some reason. reason should be noted.

there will be a visual output in the MQ window (rather lengthy)

there will be a log output in <mqfolder>\logs\testsuite
the log is DTS in its running comments, not the file name