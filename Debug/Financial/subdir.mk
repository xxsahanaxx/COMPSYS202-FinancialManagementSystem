################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Financial/Account.cpp \
../Financial/ChequeAccount.cpp \
../Financial/CreditAccount.cpp \
../Financial/Customer.cpp \
../Financial/FinancialServicesSystem.cpp \
../Financial/Money.cpp \
../Financial/SavingsAccount.cpp \
../Financial/Transaction.cpp 

OBJS += \
./Financial/Account.o \
./Financial/ChequeAccount.o \
./Financial/CreditAccount.o \
./Financial/Customer.o \
./Financial/FinancialServicesSystem.o \
./Financial/Money.o \
./Financial/SavingsAccount.o \
./Financial/Transaction.o 

CPP_DEPS += \
./Financial/Account.d \
./Financial/ChequeAccount.d \
./Financial/CreditAccount.d \
./Financial/Customer.d \
./Financial/FinancialServicesSystem.d \
./Financial/Money.d \
./Financial/SavingsAccount.d \
./Financial/Transaction.d 


# Each subdirectory must supply rules for building sources it contributes
Financial/%.o: ../Financial/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


