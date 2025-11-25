dir=$(dirname "$0")

echo "Compiling Library..."
cd $dir/lib && make && cd .. && \
echo "Compiling Program..."
make
