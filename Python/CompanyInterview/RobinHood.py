# Our goal is to build a simplified version of a real Robinhood system that reads prices from a stream and aggregates those prices into historical datapoints aka candlestick charts. We’re looking for clean code, good naming, testing, etc.
# Step 1: Parse Prices
# Your input will be a comma-separated string of prices and timestamps in the format price:timestamp e.g.
# 1:0,3:10,2:12,4:19,5:35 is equivalent to
# price: 1, timestamp: 0
# price: 3, timestamp: 10
# price: 2, timestamp: 12
# price: 4, timestamp: 19
# price: 5, timestamp: 35
# You can assume the input is sorted by timestamp and values are non-negative integers.
# Step 2: Aggregate Historical Data from Prices
# We calculate historical data across fixed time intervals. In this case, we’re interested in intervals of 10, so the first interval will be [0, 10). For each interval, you’ll build a datapoint with the following values.
# Start time
# First price
# Last price
# Max price
# Min price
# Important: If an interval has no prices, use the previous datapoint’s last price for all prices. If there are no prices and no previous datapoints, skip the interval.
# You should return a string formatted as {start,first,last,max,min}. For the prices shown above, the expected datapoints are
# {0,1,1,1,1}{10,3,4,4,2}{20,4,4,4,4}{30,5,5,5,5}

# 1:5
# {0,1,1,1,1}

# 1:21
# {20,1,1,1,1}

def solution(input: str):
    def parse_input(input: str):
        result = []
        splited_data = input.split(",")
        for item in splited_data:
            result.append(item.split(":"))

        return result

    parsed_input = parse_input(input)
    result = []
    prev_result = []
    cur_timestamp = (int(parsed_input[0][1]) // 10) * 10
    for idx, item in enumerate(parsed_input):
        timestamp = int(item[1])
        price = int(item[0])

        if ((timestamp // 10) * 10) == cur_timestamp:
            if not prev_result:
               prev_result = [cur_timestamp, price, price, price, price]
            else:
                prev_result = [cur_timestamp, prev_result[1], price, \
                    max(prev_result[3], price), min(prev_result[4], price)]
        else:
            cur_timestamp += 10
            new_timestamp = ((timestamp // 10) * 10)
            result.append(prev_result)
            prev_result = []
            #fill up old timestamp
            if cur_timestamp != new_timestamp:
                while(cur_timestamp < new_timestamp):
                    result.append([cur_timestamp, int(parsed_input[idx-1][0]), \
                        int(parsed_input[idx-1][0]), int(parsed_input[idx-1][0]), int(parsed_input[idx-1][0])])
                    cur_timestamp += 10

            prev_result = [cur_timestamp, price, price, price, price]

    if prev_result:
        result.append(prev_result)
    return result


print(solution("1:0,3:10,2:12,4:19,5:35"))
print(solution("3:10,2:12,4:19,5:25"))
print(solution("1:5"))
print(solution("1:21"))