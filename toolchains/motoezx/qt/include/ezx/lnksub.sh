ext=$1

for f in `ls .`
do
	if [ -d $f ]; then
		for h in `ls -d $f\/*$ext 2>/dev/null`
		do
			echo "linking $h to ${h##*/}..."
			ln -sf $h ${h##*/}
		done
	fi
done

