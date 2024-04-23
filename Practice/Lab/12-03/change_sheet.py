import pandas as pd

# Define file paths
excel_file_path = r"E:\Varsity\Algorithm\Algorithms Tracker Spring2024.xlsx"
output_folder = r"E:\Varsity\Algorithm"

# Read data from Excel file, specifying the header row
df = pd.read_excel(excel_file_path, header=1)  # Assuming header is in the second row

# Shuffle the DataFrame
df_shuffled = df.sample(frac=1).reset_index(drop=True)

# Check the column names in the shuffled DataFrame
print("Column names in shuffled DataFrame:", df_shuffled.columns)

# Assuming the column names are correct, proceed with creating the new DataFrame
new_df = df_shuffled[['Problem Number', 'Problem Name', 'Problem Link']].copy()
new_df['Tick Box'] = "Don't try yet"

# Specify the output file path
output_path = output_folder + r"\shuffled_problems.csv"

# Save the new DataFrame to a CSV file
new_df.to_csv(output_path, index=False)

print("New DataFrame created and saved to:", output_path)
