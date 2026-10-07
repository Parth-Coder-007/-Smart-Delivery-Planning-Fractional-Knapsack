#include <stdio.h>

#define MAX 100

int id[MAX];
float value[MAX];
float weight[MAX];
float ratio[MAX];
float fraction[MAX];

int n = 0;
float capacity = 0;
float maxValue = 0;
float totalWeight = 0;

/* Enter Package Details */
void enterDetails()
{
    int i;

    printf("\nEnter number of packages: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        id[i] = i + 1;

        printf("\nPackage %d\n", i + 1);

        printf("Enter value: ");
        scanf("%f", &value[i]);

        printf("Enter weight: ");
        scanf("%f", &weight[i]);

        if (weight[i] > 0)
            ratio[i] = value[i] / weight[i];
        else
            ratio[i] = 0;

        fraction[i] = 0;
    }

    printf("\nEnter vehicle capacity: ");
    scanf("%f", &capacity);

    maxValue = 0;
    totalWeight = 0;

    printf("\nPackage details entered successfully.\n");
}


/* Display Package Details */
void displayDetails()
{
    int i;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    printf("\n-----------------------------------------\n");
    printf("ID\tValue\tWeight\tRatio\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               id[i],
               value[i],
               weight[i],
               ratio[i]);
    }

    printf("-----------------------------------------\n");
    printf("Capacity = %.2f\n", capacity);
}


/* Calculate Value/Weight Ratio */
void calculateRatio()
{
    int i;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > 0)
            ratio[i] = value[i] / weight[i];
        else
            ratio[i] = 0;
    }

    printf("\nValue/Weight Ratio:\n");

    for (i = 0; i < n; i++)
    {
        printf("Package %d = %.2f\n", id[i], ratio[i]);
    }
}


/* Selection Sort - Decreasing Ratio */
void sortPackages()
{
    int i, j, maxIndex;

    int tempID;
    float temp;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    calculateRatio();

    /*
       Selection Sort:
       Find the package having the maximum ratio
       and place it at the current position.
    */

    for (i = 0; i < n - 1; i++)
    {
        maxIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (ratio[j] > ratio[maxIndex])
            {
                maxIndex = j;
            }
        }

        /* Swap ID */
        tempID = id[i];
        id[i] = id[maxIndex];
        id[maxIndex] = tempID;

        /* Swap Value */
        temp = value[i];
        value[i] = value[maxIndex];
        value[maxIndex] = temp;

        /* Swap Weight */
        temp = weight[i];
        weight[i] = weight[maxIndex];
        weight[maxIndex] = temp;

        /* Swap Ratio */
        temp = ratio[i];
        ratio[i] = ratio[maxIndex];
        ratio[maxIndex] = temp;
    }

    printf("\nPackages sorted using Selection Sort.\n");

    printf("\nID\tValue\tWeight\tRatio\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               id[i],
               value[i],
               weight[i],
               ratio[i]);
    }
}


/* Find Maximum Value */
void findMaximumValue()
{
    int i;
    float remainingCapacity;

    if (n == 0)
    {
        printf("\nNo package details available.\n");
        return;
    }

    /* Sort packages according to ratio */
    sortPackages();

    remainingCapacity = capacity;

    maxValue = 0;
    totalWeight = 0;

    for (i = 0; i < n; i++)
    {
        fraction[i] = 0;
    }

    /* Greedy selection */

    for (i = 0; i < n; i++)
    {
        if (remainingCapacity <= 0)
            break;

        /* Complete package */
        if (weight[i] <= remainingCapacity)
        {
            fraction[i] = 1;

            remainingCapacity =
                remainingCapacity - weight[i];

            totalWeight =
                totalWeight + weight[i];

            maxValue =
                maxValue + value[i];
        }

        /* Fraction of package */
        else
        {
            fraction[i] =
                remainingCapacity / weight[i];

            totalWeight =
                totalWeight + remainingCapacity;

            maxValue =
                maxValue +
                (value[i] * fraction[i]);

            remainingCapacity = 0;
        }
    }

    printf("\nMaximum value calculated successfully.\n");
}


/* Display Selected Packages */
void displaySelectedPackages()
{
    int i;

    printf("\n====================================================\n");
    printf("              SELECTED PACKAGES\n");
    printf("====================================================\n");

    printf("ID\tFraction\tSelected Weight\tSelected Value\n");
    printf("----------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        if (fraction[i] > 0)
        {
            printf("%d\t%.2f\t\t%.2f\t\t%.2f\n",
                   id[i],
                   fraction[i],
                   weight[i] * fraction[i],
                   value[i] * fraction[i]);
        }
    }

    printf("----------------------------------------------------\n");

    printf("Total Weight Used = %.2f\n", totalWeight);
    printf("Maximum Value      = %.2f\n", maxValue);

    printf("====================================================\n");
}


/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n\n========== FRACTIONAL KNAPSACK ==========\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("=========================================\n");

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