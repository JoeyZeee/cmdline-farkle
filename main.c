#include <stdio.h>
#include <stdlib.h>

// Unicode string constants for dice. Can be printed using "%s" - example
// provided below
char dice_faces[6][4] = {"⚀", "⚁", "⚂", "⚃", "⚄", "⚅"};
int score = 0;

int main(void) {

  int dice_vals[5];
  int face_count[7] = {0};
  // Generate the dice values (srand() followed by rand() like before)

  int seed;
  printf("srand() seed: ");
  scanf("%d", &seed);
  srand(seed);

  // generate random number from 0-5, and print dice_faces[random_num] 5 times??
	for (int i = 0; i < 5; i ++) {
		int roll = rand() % 6;
		dice_vals[i] = roll;
		face_count[roll]++;
	}

  // Print the dice values / faces. Remove this code once you understand it.
  printf("You rolled: %s (%d), %s (%d), %s (%d), %s (%d), %s (%d)",
         dice_faces[dice_vals[0]], dice_vals[0] + 1, dice_faces[dice_vals[1]], dice_vals[1] + 1, dice_faces[dice_vals[2]], dice_vals[2] + 1,
         dice_faces[dice_vals[3]], dice_vals[3] + 1, dice_faces[dice_vals[4]], dice_vals[4] + 1);


	// Analyze the dice to generate a score
	// If 3 ones are rolled, score += 1000
	if (face_count[0] >= 3) {
		score += 1000;
		face_count[0] -= 3;
	}

	if (face_count[1] >= 3) {
		score += 200;
	}

	if (face_count[2] >= 3) {
		score += 300;
	}

	if (face_count[3] >= 3) {
		score += 400;
	}

	if (face_count[4] >= 3) {
		score += 500;
		face_count[4] -= 3;
	}
		
	if (face_count[5] >= 3) {
		score += 600;
	}

	// Multiply 50 by the number of 5's stored in face_count[]
	score += face_count[4] * 50;

	// Multiply 100 by the number of 1's stored in face_count[]
	score += face_count[0] * 100;
	
  // Print the score
	if (score <= 0) {
		printf("\nThat is a score of 0 - ah well.");
	} else {
		printf("\nThat is a score of %d - congrats!", score);		
	}
  return 0;
}
