if [[ -z "$(JAVA_HOME)" ]]; then
    printf '$JAVA_HOME not provided'
    return
fi

CC=clang
JRE=$(JAVA_HOME)/bin/java
JC=$(JAVA_HOME)/bin/javac
JAR=$(JAVA_HOME)/bin/jar

C_INC=`pwd`/c_include
C_SRC=`pwd`/c_src
J_SRC=`pwd`/java_src

BUILD=`pwd`/build

C_OPTS="-fPIC -shared -I$(C_INC) -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(BUILD)/libsock.so"
J_OPTS="-h $(C_INC) -d $(BUILD)"

for f in `find -type f $(J_SRC) | grep -e '\.java$'`; do
    $(JC) $(J_OPTS) $f
done

find -type f $(C_SRC) | grep -e '\.c$' | xargs $(CC) $(C_OPTS)

print 'Enter main class: '
read mainclass
$(JAR) cfe build.jar $(mainclass) -C

print 'Would you to run this application ? [y](y/n): '
read -n 1 wanna_run
if [[ "${wanna_run,,}" != "y" ]]; then
    return
fi