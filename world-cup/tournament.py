# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME ")

    teamsx = []
    filename = sys.argv[1]
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            teamy = row
            teamy["rating"] = int(teamy["rating"])
            teamsx.append(teamy)

    counts = {}
    for simulation in range(N):
        winner = simulate_tournament(teamsx)
        if winner in counts:
            counts[winner] = counts[winner] + 1
        else:
            counts[winner] = 1

    for teamy in sorted(counts, key=lambda teamy: counts[teamy], reverse=True):
        print(f"{teamy}: {counts[teamy] * 100 / N:.1f}% chance of winning")

def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

def simulate_round(teamsx):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teamsx), 2):
        if simulate_game(teamsx[i], teamsx[i + 1]):
            winners.append(teamsx[i])
        else:
            winners.append(teamsx[i + 1])

    return winners


def simulate_tournament(teamsx):
    """Simulate a tournament. Return name of winning team."""
    rounds = len(teamsx)
    if rounds >= 2:
        teamsx = simulate_round(teamsx)
        return simulate_tournament(teamsx)

    else:
        winner = teamsx[0]["team"]
        return winner

if __name__ == "__main__":
    main()