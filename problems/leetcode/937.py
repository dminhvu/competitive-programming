from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = []
        digit_logs = []

        for log in logs:
            parts = log.split(" ", 1)  # Split only once for efficiency
            _identifier, content = parts[0], parts[1]

            # Check first character of content (more efficient)
            if content[0].isdigit():
                digit_logs.append(log)
            else:
                letter_logs.append(log)

        # Sort letter logs by content, then identifier
        letter_logs.sort(key=lambda x: (x.split(" ", 1)[1], x.split(" ", 1)[0]))

        return letter_logs + digit_logs
