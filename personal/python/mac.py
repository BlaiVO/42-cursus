import re
mac = "AA::BB-11:DDEEFF"

def validate_mac(mac):
    mac = "".join(re.split("-|:", mac))
    try:
        int(mac, 16)
    except TypeError:
        return "Malformed mac"
    return "-".join(re.findall("..", mac)) if len(mac) == 12 else "Malformed Mac"

print(validate_mac(mac))