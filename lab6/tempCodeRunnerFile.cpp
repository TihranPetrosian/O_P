int matrix[N][N];

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = std::rand() % 100; 
        }
    }

    std::cout << "Початкова матриця:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int mirroredMatrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mirroredMatrix[i][j] = matrix[N - j - 1][N - i - 1];
        }
    }

    std::cout << "Відображена матриця (відносно побічної діагоналі):" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << mirroredMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }