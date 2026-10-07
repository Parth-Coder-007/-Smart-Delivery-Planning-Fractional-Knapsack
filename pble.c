#include <stdio.h>

#define MAX 100

int id[MAX];
float profit[MAX], weight[MAX], ratio[MAX], fraction[MAX];

int n = 0;
float capacity = 0;
float maxProfit = 0;
float totalWeight = 0;

void enterDetails()
{
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        id[i] = i + 1;

        printf("\nPackage %d\n", i + 1);

        printf("Enter profit: ");
        scanf("%f", &profit[i]);

        printf("Enter weight: ");
        scanf("%f", &weight[i]);

        if (weight[i] > 0)
            ratio[i] = profit[i] / weight[i];
        else
            ratio[i] = 0;

        fraction[i] = 0;
    }

    printf("\nEnter vehicle capacity: ");
    scanf("%f", &capacity);

    maxProfit = 0;
    totalWeight = 0;

    printf("\nPackage details entered successfully.\n");
}

void displayDetails()
{
    int i;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    printf("\nID\tProfit\tWeight\tRatio\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               id[i], profit[i], weight[i], ratio[i]);
    }

    printf("\nCapacity = %.2f\n", capacity);
}

void calculateRatio()
{
    int i;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    printf("\nProfit/Weight Ratio:\n");

    for (i = 0; i < n; i++)
    {
        if (weight[i] > 0)
            ratio[i] = profit[i] / weight[i];
        else
            ratio[i] = 0;

        printf("Package %d = %.2f\n", id[i], ratio[i]);
    }
}

void sortPackages()
{
    int i, j;
    int tempID;
    float temp;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    calculateRatio();

    for (i = 0; i < n - 1; i++)
{
    for (j = 0; j < n - 1; j++)
    {
        if (ratio[j] < ratio[j + 1])
        {
            temp = ratio[j];
            ratio[j] = ratio[j + 1];
            ratio[j + 1] = temp;

            temp = profit[j];
            profit[j] = profit[j + 1];
            profit[j + 1] = temp;

            temp = weight[j];
            weight[j] = weight[j + 1];
            weight[j + 1] = temp;

            tempID = id[j];
            id[j] = id[j + 1];
            id[j + 1] = tempID;
        }
    }
}

    printf("\nPackages sorted by decreasing ratio.\n");

    printf("\nID\tProfit\tWeight\tRatio\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               id[i], profit[i], weight[i], ratio[i]);
    }
}

void findMaximumValue()
{
    int i;
    float remainingCapacity;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    sortPackages();

    remainingCapacity = capacity;
    maxProfit = 0;
    totalWeight = 0;

    for (i = 0; i < n; i++)
        fraction[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (remainingCapacity <= 0)
            break;

        if (weight[i] <= remainingCapacity)
        {
            fraction[i] = 1;

            remainingCapacity = remainingCapacity - weight[i];

            totalWeight = totalWeight + weight[i];

            maxProfit = maxProfit + profit[i];
        }
        else
        {
            fraction[i] = remainingCapacity / weight[i];

            totalWeight = totalWeight + remainingCapacity;

            maxProfit = maxProfit + (ratio[i] * remainingCapacity);

            remainingCapacity = 0;
        }
    }

    printf("\nMaximum profit calculated successfully.\n");
}

void displaySelectedPackages()
{
    int i;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    printf("\nSelected Packages\n");
    printf("ID\tFraction\tWeight\t\tProfit\n");

    for (i = 0; i < n; i++)
    {
        if (fraction[i] > 0)
        {
            printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
                   id[i],
                   fraction[i],
                   weight[i] * fraction[i],
                   profit[i] * fraction[i]);
        }
    }

    printf("\nTotal Weight Used = %.2f\n", totalWeight);
    printf("Maximum Profit = %.2f\n", maxProfit);
}

int main()
{
    int choice;

    do
    {
        printf("\nFRACTIONAL KNAPSACK\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterDetails();
                break;

            case 2:
                displayDetails();
                break;

            case 3:
                calculateRatio();
                break;

            case 4:
                sortPackages();
                break;

            case 5:
                findMaximumValue();
                break;

            case 6:
                displaySelectedPackages();
                break;

            case 7:
                printf("\nProgram terminated.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
