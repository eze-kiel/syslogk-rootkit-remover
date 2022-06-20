# `syslogk` rootkit remover

Based on the excellent article from Avast.io: [Linux Threat Hunting: ‘Syslogk’ a kernel rootkit found under development in the wild
](https://decoded.avast.io/davidalvarez/linux-threat-hunting-syslogk-a-kernel-rootkit-found-under-development-in-the-wild/)

## Shell alternative

```bash
#!/bin/bash

echo "1" > /proc/syslogk
rmnod syslogk
```

## License

WTFPL
