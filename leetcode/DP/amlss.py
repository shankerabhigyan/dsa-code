def count_disqualified_players(N, K, records):
    from collections import defaultdict

    # Adjust K only if K=0 to effectively treat it as K=1
    if K == 0:
        K = 1

    # Dictionary to track the counts of each ball number picked by each player
    player_ball_counts = defaultdict(lambda: defaultdict(int))
    # Set to track players who exceed the allowed number of picks for any ball number
    disqualified_players = set()

    # Process each record in the input list
    for player_id, ball_number in records:
        # Increment the count of how many times this player has picked this ball number
        player_ball_counts[player_id][ball_number] += 1

        # Check if the count exceeds the allowed number of picks (K)
        if player_ball_counts[player_id][ball_number] > K:
            # Add the player to the set of disqualified players
            disqualified_players.add(player_id)

    # The output is the number of unique disqualified players
    return len(disqualified_players)

# Example usage:
N = 8
K = 0  # This means players can pick the same ball only once without disqualification
records = [[10,6],[3,1],[10,6],[10,6],[4,5],[3,1],[3,5],[3,1]]
# Expected Output: 2, since players 10 and 3 pick the same ball more than once
print(count_disqualified_players(N, K, records))


N1 = 6
K1 = 0
records1 = [[5, 2], [3, 6], [5, 4], [2, 8], [5, 4], [5, 4]]
# Expected Output: 1, since player 5 picks the same ball number 4 more than once
print(count_disqualified_players(N1, K1, records1))