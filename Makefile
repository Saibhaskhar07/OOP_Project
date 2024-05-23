CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = main.cpp Accounts.cpp Admin.cpp Cards.cpp Commercial.cpp Loan.cpp Personal.cpp PersonalLoan.cpp StudentLoan.cpp User.cpp Utils.cpp loading.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = bankeasy

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
