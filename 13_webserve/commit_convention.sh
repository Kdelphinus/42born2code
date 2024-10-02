#!/bin/bash

prepare_commit_msg_path=".git/hooks/prepare-commit-msg"

# Content of the prepare-commit-msg file
prepare_commit_msg_content="#!/bin/bash

commit_msg_title=\$(head -n 1 \"\$1\")
commit_msg_body=\$(tail -n +2 \"\$1\")

# Regular expression pattern to match specific commit types at the beginning of the commit message
commit_type_regex=\"^(\\[(Add|Edit|Fix|Test|Delete|Doc)\\])\"

if [[ ! \$commit_msg_title =~ \$commit_type_regex ]]; then
	red=\$(tput setaf 1)
	reset=\$(tput sgr0)
	echo -e \"\${red}Invalid commit type. Available commit types: [Add], [Edit], [Fix], [Test], [Delete], [Doc]\${reset}\"
	exit 1
fi
"

if [ -f "$prepare_commit_msg_path" ]; then
  rm "$prepare_commit_msg_path"
  echo -e "$(tput setaf 1)Deleted existing prepare-commit-msg file$(tput sgr0)"
fi

# Create the prepare-commit-msg file
echo "$prepare_commit_msg_content" > "$prepare_commit_msg_path"
chmod +x "$prepare_commit_msg_path"

echo -e "$(tput setaf 2)prepare-commit-msg file has been added to .git/hooks folder.$(tput sgr0)"
