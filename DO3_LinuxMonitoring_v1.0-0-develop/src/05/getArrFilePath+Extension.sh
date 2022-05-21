var=$1
fullfile=$var

# echo $1 | sed -E 's|.*\.([^\.]*)$|\1|g'

# var=${var#*.}
# echo ${var##*.}

extension=$(file -L $var | cut -d" " -f 2)
echo "$fullfile $extension" 

# filename=$(basename -- "$fullfile")
# extension="${filename##*.}"
# filename="${filename%.*}"
# echo "$fullfile $extension" 