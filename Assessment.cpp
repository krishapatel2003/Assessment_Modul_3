#include<iostream>
#include<cmath> 
using namespace std;

class Event 
{
	private:
    	string eventName;
   		string firstName; 
		string lastName;
    	int numberOfGuests;
    	int numberOfMinutes;
    	int numberOfServers;

    	const double CostPerHour=18.50;
    	const double CostPerMinute=0.40;
    	const double CostOfDinner=20.70;

	public:
	    void getInput() 
		{
    	    cout<<"******************Event Management System*******************\n";
	        cout<<"Enter the name of the event: ";
        	cin>>eventName;
        	cout<<"Enter your first name: ";
        	cin>>firstName;
        	cout<<"Enter your last name: ";
        	cin>>lastName;
        	cout<<"Enter the number of guests: ";
        	cin>>numberOfGuests;
        	cout<<"Enter the number of minutes the event will last: ";
        	cin>>numberOfMinutes;
    }

    void calculateServers() 
	{
        numberOfServers=ceil(static_cast<double>(numberOfGuests)/20);
    }

    double calculateCostForOneServer() 
	{
    	double cost1=(numberOfMinutes/60)*CostPerHour;
    	double cost2=(numberOfMinutes%60)*CostPerMinute;
    	return cost1+cost2;
    }

    double calculateFoodCost() 
	{
        return numberOfGuests*CostOfDinner;
    }

    double calculateAverageCost(double totalFoodCost) 
	{
        return totalFoodCost/numberOfGuests;
    }

    double calculateTotalCost(double totalFoodCost, double costForOneServer) 
	{
        return totalFoodCost+(costForOneServer*numberOfServers);
    }

    double calculateDepositAmount(double totalCost) 
	{
        return totalCost*0.25;
    }

    void displayResults() 
	{
        double costForOneServer=calculateCostForOneServer();
        double totalFoodCost=calculateFoodCost();
        double totalCost=calculateTotalCost(totalFoodCost, costForOneServer);
        double depositAmount=calculateDepositAmount(totalCost);
        double averageCost=calculateAverageCost(totalFoodCost);

        cout<<"\n*********************Event Details*************************\n";
        cout<<"\n Event Name: "<<eventName;
        cout<<"\n Organizer: "<<firstName<<" "<<lastName;
        cout<<"\n Number of Guests: "<<numberOfGuests;
        cout<<"\n Event Duration: "<<numberOfMinutes<<" minutes";

        cout<<"\n*********************Cost Breakdown*********************\n";
        cout<<"\n Number of Servers Required: "<<numberOfServers;
        cout<<"\n Cost for One Server: "<<costForOneServer;
        cout<<"\n Total Food Cost: "<<totalFoodCost;
        cout<<"\n Average Cost Per Person: "<<averageCost;
        cout<<"\n Total Event Cost: "<<totalCost;
        cout<<"\n Deposit Amount (25%): "<<depositAmount;
    }
};

int main() 
{
    Event event;
    event.getInput();
    event.calculateServers(); 
    event.displayResults();  

    return 0;
}
