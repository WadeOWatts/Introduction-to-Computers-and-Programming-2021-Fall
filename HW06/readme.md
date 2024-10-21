### Homework 6 Description

To maintain one's body weight, an adult human needs to consume enough calories daily to:
1. Meet the basal metabolic rate (energy required to breathe, maintain body temperature, etc.),
2. Account for physical activity such as exercise, and
3. Account for the energy required to digest the food that is being eaten.

For an adult that weighs \( P \) pounds, we can estimate these caloric requirements using the following formulas:

#### A. Basal Metabolic Rate
Calories required:
$$
70 \times \left(\frac{P}{2.2}\right)^{0.756}
$$

#### B. Physical Activity
Calories required:
$$
0.0385 \times \text{Intensity} \times P \times \text{Minutes}
$$

Here, **Minutes** is the number of minutes spent during the physical activity, and **Intensity** is a number that estimates the intensity of the activity. Here are some sample numbers for the range of values:

| Activity        | Intensity |
|-----------------|-----------|
| Running 10 mph  |    17     |
| Running 6 mph   |    10     |
| Basketball      |     8     |
| Walking 1 mph   |     1     |

#### C. Energy to Digest Food
Calories required:
$$
\text{TotalCaloriesConsumed} \times 0.1
$$

In other words, 10 percent of the calories we consume go towards digestion.

---

Write a function that computes the calories required for the basal metabolic rate, taking as input a parameter for the person’s weight. Write another function that computes the calories required for physical activity, taking as input parameters for the intensity, weight, and minutes spent exercising.

Use these functions in a program that inputs a person’s weight, an estimate for the intensity of physical activity, the number of minutes spent performing the physical activity, and the number of calories in one serving of your favorite food. The program should then calculate and output how many servings of that food should be eaten per day to maintain the person’s current weight at the specified activity level. The computation should include the energy that is required to digest food.
