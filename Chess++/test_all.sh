echo "Compiling main..."
g++ -o chess main.cpp
echo "Running with all sample inputs"
mkdir generated_outputs
./chess < sample_input/ez_win.txt > generated_outputs/ez_win_out.txt
./chess < sample_input/forgot_the_rules.txt > generated_outputs/forgot_the_rules_out.txt
./chess < sample_input/little_win.txt > generated_outputs/little_win_out.txt
./chess < sample_input/no_cheating.txt > generated_outputs/no_cheating_out.txt
rm chess
echo "Done! See Generated Outputs for Your Outputs"